/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   VirtualMachine.cpp                                 :+:      :+:    :+:    */
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

#ifndef __ABSTRACT_VM_SOURCES_VIRTUAL_MACHINE
# define __ABSTRACT_VM_SOURCES_VIRTUAL_MACHINE

# include "../include/abstract_vm.hpp"
# include "../include/VirtualMachine.hpp"
# include <iostream>

void abstract_vm::VirtualMachine::init(void)
{

}

abstract_vm::VirtualMachine::VirtualMachine(void)
{
	this->init();
}

abstract_vm::VirtualMachine::~VirtualMachine(void)
{
	this->clear();
}

abstract_vm::VirtualMachine::VirtualMachine(const abstract_vm::VirtualMachine& other)
{
	this->init();
	*this = other;
}

abstract_vm::VirtualMachine& abstract_vm::VirtualMachine::operator=(const abstract_vm::VirtualMachine& other)
{
	if (this != &other)
	{

	}
	return (*this);
}

void abstract_vm::VirtualMachine::clear(void)
{

}

#endif//!__ABSTRACT_VM_SOURCES_VIRTUAL_MACHINE
