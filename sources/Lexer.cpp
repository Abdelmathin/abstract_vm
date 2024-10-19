/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:    */
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

#ifndef __ABSTRACT_VM_SOURCES_LEXER
# define __ABSTRACT_VM_SOURCES_LEXER

# include "../include/abstract_vm.hpp"
# include "../include/Lexer.hpp"
# include "../include/Token.hpp"
# include <iostream>
# include <exception>

void abstract_vm::Lexer::init(void)
{
	this->_tokens.clear();
	this->setIndex(0);
	this->setBuffer("");
}

abstract_vm::Lexer::Lexer(void)
{
	this->init();
}

abstract_vm::Lexer::~Lexer(void)
{
	this->clear();
}

abstract_vm::Lexer::Lexer(const abstract_vm::Lexer& other)
{
	this->init();
	*this = other;
}

abstract_vm::Lexer& abstract_vm::Lexer::operator=(const abstract_vm::Lexer& other)
{
	if (this != &other)
	{
		this->_tokens = other._tokens;
	}
	return (*this);
}

char abstract_vm::Lexer::peek(void) const
{
	if (this->_index < this->_buffer.size())
	{
		return (this->_buffer[this->_index]);
	}
	return ('\0');
}

bool abstract_vm::Lexer::eof(void) const
{
	return (this->_index >= this->_buffer.size());
}

std::string::size_type abstract_vm::Lexer::getIndex(void) const
{
	return (this->_index);
}

std::string abstract_vm::Lexer::getBuffer(void) const
{
	return (this->_buffer);
}

void abstract_vm::Lexer::setIndex(std::string::size_type index)
{
	this->_index = index;
}

void abstract_vm::Lexer::setBuffer(const std::string& buffer)
{
	this->_buffer = buffer;
}

void abstract_vm::Lexer::advance(void)
{
	if (!this->eof())
	{
		this->_index++;
	}
}

void abstract_vm::Lexer::addComment(void)
{
	std::string res = "";
	while (!this->eof())
	{
		if (this->peek() == CHARACTER_CARRIAGE_RETURN)
		{
			this->advance();
			if ((this->eof()) || (this->peek() == CHARACTER_LINE_FEED))
			{
				this->advance();
				break ;
			}
			res += CHARACTER_CARRIAGE_RETURN;
			continue ;
		}
		res += this->peek();
		this->advance();
	}
	this->_tokens.push_back(abstract_vm::Token(TOKEN_TYPE_COMMENT, res));
}

void abstract_vm::Lexer::addWord(void)
{
	std::string res = "";
	while (!this->eof())
	{
		switch (this->peek())
		{
			case CHARACTER_TAB:
			case CHARACTER_SPACE:
			case CHARACTER_LINE_FEED:
			case CHARACTER_CARRIAGE_RETURN:
			case CHARACTER_LEFT_PARENTHESIS:
			case CHARACTER_RIGHT_PARENTHESIS:
				return (this->_tokens.push_back(abstract_vm::Token(TOKEN_TYPE_WORD, res)));
			default:
			{
				res += this->peek();
				this->advance();
			}
		}
	}
	return (this->_tokens.push_back(abstract_vm::Token(TOKEN_TYPE_WORD, res)));
}

void abstract_vm::Lexer::tokenize(void)
{
	while (!this->eof())
	{
		switch (this->peek())
		{
			case CHARACTER_TAB:
			case CHARACTER_SPACE:
			case CHARACTER_LINE_FEED:
			case CHARACTER_CARRIAGE_RETURN:
			case CHARACTER_LEFT_PARENTHESIS:
			case CHARACTER_RIGHT_PARENTHESIS:
			{
				this->_tokens.push_back(abstract_vm::Token(this->peek(), this->peek()));
				this->advance();
				break;
			}
			case CHARACTER_SEMICOLON:
				this->addComment();
				break;
			default:
				this->addWord();
		}
	}
}

void abstract_vm::Lexer::clear(void)
{
	this->_tokens.clear();
	this->setIndex(0);
	this->setBuffer("");
}

#endif//!__ABSTRACT_VM_SOURCES_LEXER
