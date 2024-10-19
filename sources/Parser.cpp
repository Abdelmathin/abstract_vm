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

	}
	return (*this);
}

void abstract_vm::Parser::setLexer(abstract_vm::Lexer lexer)
{
	this->_lexer = lexer;
}

void abstract_vm::Parser::parse(void)
{
	// abstract_vm::Lexer::iterator it = lexer.begin();
	// while (it != lexer.end())
	// {
	// 	it++;
	// }
	// (void) lexer;
	exit(0);
}

void abstract_vm::Parser::clear(void)
{

}

#endif//!__ABSTRACT_VM_SOURCES_PARSER
