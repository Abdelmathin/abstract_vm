/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:    */
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

#ifndef __ABSTRACT_VM_SOURCES_TOKEN
# define __ABSTRACT_VM_SOURCES_TOKEN

# include "../include/abstract_vm.hpp"
# include "../include/Token.hpp"
# include <iostream>

abstract_vm::Token::Token(void)
{
	this->_type = TOKEN_TYPE_UNKNOWN;
	this->_str  = "";
}

abstract_vm::Token::Token(const Token& other)
{
	*this = other;
}

abstract_vm::Token& abstract_vm::Token::operator=(const abstract_vm::Token& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		this->_str  = other._str ;
	}
	return (*this);
}

abstract_vm::Token::~Token(void)
{
	this->_type = TOKEN_TYPE_UNKNOWN;
	this->_str  = "";
}

abstract_vm::Token::Token(int type, std::string str)
{
	this->setType(type);
	this->setStr(str);
}

abstract_vm::Token::Token(int type, char chr)
{
	std::string str = "";
	str += chr;
	this->setType(type);
	this->setStr(str);
}

int abstract_vm::Token::getType(void) const
{
	return (this->_type);
}

std::string abstract_vm::Token::getStr(void) const
{
	return (this->_str);
}

void abstract_vm::Token::setType(int type)
{
	this->_type = type;
}

void abstract_vm::Token::setStr(std::string str)
{
	this->_str = str;
}

#endif//!__ABSTRACT_VM_SOURCES_TOKEN
