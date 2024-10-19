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
# include <iostream>

void abstract_vm::Lexer::init(void)
{
	this->_tokens.clear();
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

void abstract_vm::Lexer::clear(void)
{
	this->_tokens.clear();
}

#endif//!__ABSTRACT_VM_SOURCES_LEXER
