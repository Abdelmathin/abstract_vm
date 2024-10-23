/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Instruction.cpp                                    :+:      :+:    :+:    */
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

#ifndef __ABSTRACT_VM_SOURCES_INSTRUCTION
# define __ABSTRACT_VM_SOURCES_INSTRUCTION

# include "../include/abstract_vm.hpp"
# include "../include/Instruction.hpp"
# include "../include/IOperand.hpp"
# include <iostream>

abstract_vm::Instruction::Instruction(void)
{
	this->_keyword = 0;
	this->_operand = 0;
}

abstract_vm::Instruction::Instruction(const abstract_vm::Instruction& other)
{
	*this = other;
}

abstract_vm::Instruction& abstract_vm::Instruction::operator=(const abstract_vm::Instruction& other)
{
	if (this != &other)
	{
		this->_keyword = other._keyword;
		this->_operand = other._operand;
	}
	return (*this);
}

abstract_vm::Instruction::~Instruction(void)
{
	this->_keyword = 0;
	this->_operand = 0;
}

abstract_vm::Instruction::Instruction(int keyword, abstract_vm::IOperand* operand)
{
	this->_keyword = keyword;
	this->_operand = operand;
}

int abstract_vm::Instruction::getKeyword(void) const
{
	return (this->_keyword);
}

abstract_vm::IOperand* abstract_vm::Instruction::getOperand(void) const
{
	return (this->_operand);
}

void abstract_vm::Instruction::setKeyword(int keyword)
{
	this->_keyword = keyword;
}

void abstract_vm::Instruction::setOperand(abstract_vm::IOperand* operand)
{
	this->_operand = operand;
}

#endif//!__ABSTRACT_VM_SOURCES_INSTRUCTION
