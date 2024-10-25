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
# include <sstream>

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

IOperand const * abstract_vm::Parser::createOperand( eOperandType type, std::string const & value ) const
{
	(void) type;
	(void) value;
	return (NULL);
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
			case TOKEN_TYPE_CARRIAGE_RETURN:
				this->advance();
				break ;
			default:
				return (true);
		}
	}
	return (false);
}

bool abstract_vm::Parser::skipEmptyTokens(void)
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
	return (true);
}

bool abstract_vm::Parser::skipWhiteTokens(void)
{
	if (_tpos >= _tokens.size())
	{
		return (true);
	}
	if (_tokens[_tpos].getType() != TOKEN_TYPE_LINE_FEED)
	{
		return (false);
	}
	this->skipEmptyTokens();
	return (true);
}

bool abstract_vm::Parser::syntaxError(void)
{
	return (false);
}


bool abstract_vm::Parser::push(void)
{
	this->skipEmptyTokens();
	if ((_tpos >= _tokens.size()) || (this->currentToken().getType() != TOKEN_TYPE_WORD))
	{
		return (false);
	}
	if (this->currentToken().getValue() != KEYWORD_NAME_PUSH)
	{
		return (false);
	}
	this->advance();
	this->skipBlankTokens();
	if (this->currentToken().getType() != TOKEN_TYPE_WORD)
	{
		return (false);
	}
	int type = -1;
	std::string types[] = {
		DATA_TYPENAME_INT8  ,
		DATA_TYPENAME_INT16 ,
		DATA_TYPENAME_INT32 ,
		DATA_TYPENAME_INT64 ,
		DATA_TYPENAME_FLOAT ,
		DATA_TYPENAME_DOUBLE,
		DATA_TYPENAME_IMAGE
	};
	for (int i = 0; i < 7; i++)
	{
		if (this->currentToken().getValue() == types[i])
		{
			type = i;
			break ;
		}
	}
	if (type < 0)
	{
		return (this->syntaxError());
	}
	this->advance();
	this->skipBlankTokens();
	if (currentToken().getType() != CHARACTER_LEFT_PARENTHESIS)
	{
		return (this->syntaxError());
	}
	this->advance();
	this->skipBlankTokens();

	abstract_vm::IOperand* operand = this->createOperand(type, currentToken().getValue());
	if (!operand)
	{
		return (this->syntaxError());
	}
	this->_instructions.push(abstract_vm::Instruction(INSTRUCTION_PUSH, operand));

	this->advance();
	this->skipBlankTokens();
	if (currentToken().getType() != CHARACTER_RIGHT_PARENTHESIS)
	{
		return (this->syntaxError());
	}
	this->advance();
	this->skipBlankTokens();
	if (currentToken().getType() != TOKEN_TYPE_LINE_FEED)
	{
		return (this->syntaxError());
	}
	this->skipEmptyTokens();
	return (true);
}

bool abstract_vm::Parser::addInstruction(void)
{
	this->skipEmptyTokens();
	if (this->currentToken().getType() != TOKEN_TYPE_WORD)
	{
		return (false);
	}
	if (this->currentToken().getValue() != KEYWORD_NAME_ADD)
	{
		return (false);
	}
	this->advance();
	this->skipBlankTokens();
	if (this->skipWhiteTokens() == false)
	{
		return (this->syntaxError());
	}
	// Instruction(add)
	return (true);
}

bool abstract_vm::Parser::mulInstruction(void)
{
	this->skipEmptyTokens();
	if (this->currentToken().getType() != TOKEN_TYPE_WORD)
	{
		return (false);
	}
	if (this->currentToken().getValue() != KEYWORD_NAME_MUL)
	{
		return (false);
	}
	this->advance();
	this->skipBlankTokens();
	if (this->skipWhiteTokens() == false)
	{
		return (this->syntaxError());
	}
	// Instruction(mul)
	return (true);
}

bool abstract_vm::Parser::dumpInstruction(void)
{
	this->skipEmptyTokens();
	if (this->currentToken().getType() != TOKEN_TYPE_WORD)
	{
		return (false);
	}
	if (this->currentToken().getValue() != KEYWORD_NAME_DUMP)
	{
		return (false);
	}
	this->advance();
	this->skipBlankTokens();
	if (this->skipWhiteTokens() == false)
	{
		return (this->syntaxError());
	}
	// Instruction(dump)
	return (true);
}

bool abstract_vm::Parser::popInstruction(void)
{
	this->skipEmptyTokens();
	if (this->currentToken().getType() != TOKEN_TYPE_WORD)
	{
		return (false);
	}
	if (this->currentToken().getValue() != KEYWORD_NAME_POP)
	{
		return (false);
	}
	this->advance();
	this->skipBlankTokens();
	if (this->skipWhiteTokens() == false)
	{
		return (this->syntaxError());
	}
	// Instruction(pop)
	return (true);
}

bool abstract_vm::Parser::printInstruction(void)
{
	this->skipEmptyTokens();
	if (this->currentToken().getType() != TOKEN_TYPE_WORD)
	{
		return (false);
	}
	if (this->currentToken().getValue() != KEYWORD_NAME_PRINT)
	{
		return (false);
	}
	this->advance();
	this->skipBlankTokens();
	if (this->skipWhiteTokens() == false)
	{
		return (this->syntaxError());
	}
	// Instruction(print)
	return (true);
}

bool abstract_vm::Parser::exitInstruction(void)
{
	this->skipEmptyTokens();
	if (this->currentToken().getType() != TOKEN_TYPE_WORD)
	{
		return (false);
	}
	if (this->currentToken().getValue() != KEYWORD_NAME_EXIT)
	{
		return (false);
	}
	this->advance();
	this->skipBlankTokens();
	if (this->skipWhiteTokens() == false)
	{
		return (this->syntaxError());
	}
	// Instruction(exit)
	return (true);
}

void abstract_vm::Parser::parse(void)
{
	_tpos = 0;
	while (_tpos < _tokens.size())
	{
		if (this->push())
		{
			continue ;
		}
		if (this->addInstruction())
		{
			continue ;
		}
		if (this->printInstruction())
		{
			continue ;
		}
		if (this->exitInstruction())
		{
			break ;
		}
		std::cout << ">>>>> [" << currentToken().getValue() << "]" << std::endl;
		exit(0);
	}
	if (_tpos < _tokens.size())
	{
		// instructions after exit or somthing...
		std::cout << "error [" << currentToken().getValue() << "]" << std::endl;
		exit(0);
	}
}

void abstract_vm::Parser::clear(void)
{
	this->_tokens.clear();
	this->_instructions.clear();
}

#endif//!__ABSTRACT_VM_SOURCES_PARSER
