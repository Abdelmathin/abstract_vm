/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+      */
/*   By: ahabachi <abdelmathinhabachi@gmail.com>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+            */
/*   Created: 2024/08/19 17:40:12 by ahabachi          #+#    #+#              */
/*   Updated: 2024/09/24 06:34:37 by ahabachi         ###   ########.fr        */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*            _    _         _                  _    __     ____  __           */
/*           / \  | |__  ___| |_ _ __ __ _  ___| |_  \ \   / /  \/  |          */
/*          / _ \ | '_ \/ __| __| '__/ _` |/ __| __|  \ \ / /| |\/| |          */
/*         / ___ \| |_) \__ \ |_| | | (_| | (__| |_    \ V / | |  | |          */
/*        /_/   \_\_.__/|___/\__|_|  \__,_|\___|\__|    \_/  |_|  |_|          */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*  █████████            ██████████         ██████████         ██████████      */
/*  ██     ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██            ██████████         ██████████                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*      ████████         ██████████         ██████████                 ██      */
/*                                                                             */
/* **************************************************************************  */

#ifndef __ABSTRACT_VM_SOURCES_PARSER
# define __ABSTRACT_VM_SOURCES_PARSER

# include "../include/abstract_vm.hpp"
# include "../include/Parser.hpp"
# include "../include/Lexer.hpp"
# include <iostream>

void abstract_vm::Parser::init(void)
{
	this->_tokens.clear();
	this->_instructions.clear();
}

abstract_vm::Parser::Parser(void)
{
	this->init();
}

abstract_vm::Parser::~Parser(void)
{
	this->clear();
}

abstract_vm::Parser::Parser(const abstract_vm::Parser& other)
{
	this->init();
	*this = other;
}

abstract_vm::Parser& abstract_vm::Parser::operator=(const abstract_vm::Parser& other)
{
	if (this != &other)
	{
		this->_tokens       = other._tokens;
		this->_instructions = other._instructions;
	}
	return (*this);
}

void abstract_vm::Parser::setTokens(const std::vector< abstract_vm::Token >& tokens)
{
	this->_tokens = tokens;
}

bool abstract_vm::Parser::advance(void)
{
	if (_tpos < _tokens.size())
	{
		_tpos++;
		return (true);
	}
	return (false);
}

abstract_vm::Token abstract_vm::Parser::currentToken(void)
{
	if (_tpos < _tokens.size())
	{
		return (_tokens[_tpos]);
	}
	return (abstract_vm::Token(TOKEN_TYPE_UNKNOWN, ""));
}

bool abstract_vm::Parser::skipBlankTokens(void)
{
	while (_tpos < _tokens.size())
	{
		switch (_tokens[_tpos].getType())
		{
			case TOKEN_TYPE_TAB:
			case TOKEN_TYPE_SPACE:
			case TOKEN_TYPE_COMMENT:
			case TOKEN_TYPE_LINE_FEED:
			case TOKEN_TYPE_CARRIAGE_RETURN:
				this->advance();
				break ;
			default:
				return (true);
		}
	}
	return (false);
}

bool abstract_vm::Parser::syntaxError(void)
{
	return (false);
}

bool abstract_vm::Parser::pushInt8(void)
{
	throw std::logic_error("Not implemented: pushInt8");
	return (false);
}

bool abstract_vm::Parser::pushInt16(void)
{
	throw std::logic_error("Not implemented: pushInt16");
	return (false);
}

bool abstract_vm::Parser::pushInt32(void)
{
	throw std::logic_error("Not implemented: pushInt32");
	return (false);
}

bool abstract_vm::Parser::pushInt64(void)
{
	throw std::logic_error("Not implemented: pushInt64");
	return (false);
}

bool abstract_vm::Parser::pushFloat(void)
{
	throw std::logic_error("Not implemented: pushFloat");
	return (false);
}

bool abstract_vm::Parser::pushDouble(void)
{
	throw std::logic_error("Not implemented: pushDouble");
	return (false);
}

bool abstract_vm::Parser::pushImage(void)
{
	throw std::logic_error("Not implemented: pushImage");
	return (false);
}

bool abstract_vm::Parser::pushInstruction(void)
{
	if (_tpos >= _tokens.size())
	{
		return (false);
	}
	if (this->currentToken().getType() != TOKEN_TYPE_WORD)
	{
		return (false);
	}
	if (this->currentToken().getValue() != "push")
	{
		return (false);
	}
	this->advance();
	this->skipBlankTokens();
	if (this->currentToken().getType() != TOKEN_TYPE_WORD)
	{
		return (this->syntaxError());
	}
	const std::string name = this->currentToken().getValue();
	if (name == "int8")
		return (this->pushInt8());
	if (name == "int16")
		return (this->pushInt16());
	if (name == "int32")
		return (this->pushInt32());
	if (name == "int64")
		return (this->pushInt64());
	if (name == "float")
		return (this->pushFloat());
	if (name == "double")
		return (this->pushDouble());
	if (name == "image")
		return (this->pushImage());
	return (this->syntaxError());
}

void abstract_vm::Parser::parse(void)
{
	for (_tpos = 0; _tpos < _tokens.size(); _tpos++)
	{
		const abstract_vm::Token& token = _tokens[_tpos];
		this->skipBlankTokens();
		this->pushInstruction();
		// if (token.getValue() == "push")
		// {
		// 	this->pushInstruction();
		// 	_tpos++;
		// }
		std::cout << token.getValue() << std::endl;
		// const int type          = tokens[i].getType();
		// const std::string value = tokens[i].getValue();
		// switch (type)
		// {
		// 	case TOKEN_TYPE_TAB:
		// 	case TOKEN_TYPE_SPACE:
		// 	case TOKEN_TYPE_COMMENT:
		// 	case TOKEN_TYPE_LINE_FEED:
		// 	case TOKEN_TYPE_CARRIAGE_RETURN:
		// 		continue ;
		// }
		// if (type == TOKEN_TYPE_WORD)
		// {
		// 	if (value == "push")
		// 	{

		// 	}
		// 	std::cout << tokens[i].getValue() << std::endl;
		// }
	}
	exit(0);
}

void abstract_vm::Parser::clear(void)
{
	this->_tokens.clear();
	this->_instructions.clear();
}

#endif//!__ABSTRACT_VM_SOURCES_PARSER
