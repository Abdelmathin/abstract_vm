/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   OStream.cpp                                        :+:      :+:    :+:    */
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

#ifndef __ABSTRACT_VM_SOURCES_OSTREAM
# define __ABSTRACT_VM_SOURCES_OSTREAM

# include "../include/abstract_vm.hpp"
# include "../include/OStream.hpp"
# include <iostream>
# include <sstream>
# include <unistd.h>

void abstract_vm::OStream::init(void)
{
	this->_fdout  = -1;
	this->_stream.str("");
}

abstract_vm::OStream::OStream(void)
{
	this->init();
}

abstract_vm::OStream::OStream(const abstract_vm::OStream& other)
{
	this->init();
	*this = other;
}

abstract_vm::OStream& abstract_vm::OStream::operator=(const abstract_vm::OStream& other)
{
	if (this != &other)
	{
		this->_fdout = other._fdout;
		this->_stream.str(other._stream.str());
	}
	return (*this);
}

abstract_vm::OStream& abstract_vm::OStream::operator<<(const std::string& msg)
{
	if (msg == abstract_vm::crlf)
	{
		if (this->getFdOut() >= 0)
		{
			const std::string str = this->_stream.str();
			write(this->getFdOut(), str.data(), str.size());
			write(this->getFdOut(), msg.data(), msg.size());
		}
		this->_stream.str("");
		return (*this);
	}
	this->_stream << msg;
	return (*this);
}

abstract_vm::OStream::~OStream(void)
{
	this->clear();
}

int  abstract_vm::OStream::getFdOut(void) const
{
	return (this->_fdout);
}

void abstract_vm::OStream::setFdOut(int fd)
{
	this->_fdout = fd;
}

void abstract_vm::OStream::clear(void)
{
	this->_fdout  = -1;
	this->_stream.str("");
}

#endif//!__ABSTRACT_VM_SOURCES_OSTREAM
