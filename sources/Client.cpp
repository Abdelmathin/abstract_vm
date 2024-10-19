/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:    */
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

#include "../include/Client.hpp"
#include "../include/OStream.hpp"
#include "../include/Lexer.hpp"
#include "../include/Parser.hpp"
#include "../include/VirtualMachine.hpp"
#include <iostream>
#include <unistd.h>

void abstract_vm::Client::init(void)
{
    this->setFdIn(-1)                             ;
    this->setFdOut(-1)                            ;
    this->setFdErr(-1)                            ;
    this->setConnected(false)                     ;
    this->setBuffer("")                           ;
    this->setEOS("")                              ;
    this->setOutputstream(abstract_vm::OStream()) ;
    this->setErrorstream(abstract_vm::OStream())  ;
    this->setLexer(abstract_vm::Lexer())          ;
    this->setParser(abstract_vm::Parser())        ;
    this->setVm(abstract_vm::VirtualMachine())    ;
}

abstract_vm::Client::Client(void)
{
    this->init();
}

abstract_vm::Client::~Client(void)
{
    this->clear();
}

abstract_vm::Client::Client(const abstract_vm::Client& other)
{
    this->init();
    *this = other;
}

abstract_vm::Client& abstract_vm::Client::operator=(const abstract_vm::Client& other)
{
    if (this != &other)
    {
        this->setFdIn(other.getFdIn())             ;
        this->setFdOut(other.getFdOut())           ;
        this->setFdErr(other.getFdErr())           ;
        this->setConnected(other.isConnected())    ;
        this->setBuffer(other.getBuffer())         ;
        this->setEOS(other.getEOS())               ;
        this->setOutputstream(other._outputstream) ;
        this->setErrorstream(other._errorstream)   ;
        this->setLexer(other._lexer)               ;
        this->setParser(other._parser)             ;
        this->setVm(other._vm)                     ;
    }
    return (*this);
}

int abstract_vm::Client::getFdIn(void) const
{
    return (this->_fdin);
}

int abstract_vm::Client::getFdOut(void) const
{
    return (this->_fdout);
}

int abstract_vm::Client::getFdErr(void) const
{
    return (this->_fderr);
}

bool abstract_vm::Client::isConnected(void) const
{
    return (this->_connected);
}

std::string abstract_vm::Client::getBuffer(void) const
{
    return (this->_buffer);
}

std::string abstract_vm::Client::getEOS(void) const
{
    return (this->_eos);
}

void abstract_vm::Client::setFdIn(int fdin)
{
    this->_fdin = fdin;
}

void abstract_vm::Client::setFdOut(int fdout)
{
    this->_fdout = fdout;
}

void abstract_vm::Client::setFdErr(int fderr)
{
    this->_fderr = fderr;
}

void abstract_vm::Client::setConnected(bool status)
{
    this->_connected = status;
}

void abstract_vm::Client::setBuffer(const std::string& buffer)
{
    this->_buffer = buffer;
}

void abstract_vm::Client::setEOS(const std::string& eos)
{
    this->_eos = eos;
}

void abstract_vm::Client::setOutputstream(const abstract_vm::OStream& stream)
{
    this->_outputstream = stream;
}

void abstract_vm::Client::setErrorstream(const abstract_vm::OStream& stream)
{
    this->_errorstream = stream;
}

void abstract_vm::Client::setLexer(const abstract_vm::Lexer& lexer)
{
    this->_lexer = lexer;
}

void abstract_vm::Client::setParser(const abstract_vm::Parser& parser)
{
    this->_parser = parser;
}

void abstract_vm::Client::setVm(const abstract_vm::VirtualMachine& vm)
{
    this->_vm = vm;
}

void abstract_vm::Client::clear(void)
{
    this->setFdIn(-1)           ;
    this->setFdOut(-1)          ;
    this->setFdErr(-1)          ;
    this->setConnected(false)   ;
    this->_buffer.clear()       ;
    this->_eos.clear()          ;
    this->_outputstream.clear() ;
    this->_errorstream.clear()  ;
    this->_lexer.clear()        ;
    this->_parser.clear()       ;
    this->_vm.clear()           ;
}

int abstract_vm::Client::read(void)
{
    if (!this->isConnected() || (this->getFdIn() < 0))
    {
        this->setConnected(false);
        return (-1);
    }
    char tmpbuffer[1024];
    const int rd = ::read(this->getFdIn(), tmpbuffer, 1024);
    if (rd > 0)
    {
        std::string tmp(tmpbuffer, rd);
        if (rd < 1024)
        {
            tmp += "\n";
        }
        this->addBuffer(tmp);
        return (rd);
    }
    this->setConnected(false);
    return (-1);
}

void abstract_vm::Client::checkLine(void)
{
    std::string::size_type i = 0;
    std::string::size_type l = this->getBuffer().length();
    while (i < l)
    {
        int p = (this->getBuffer()[i] == '\n');
        if (((i + 1) < l) && (this->getBuffer()[i] == '\r') && (this->getBuffer()[i + 1] == '\n'))
        {
            p = 2;
        }
        if (p != 0)
        {
            std::string user_input = this->getBuffer().substr(0, i);
            this->setBuffer(this->getBuffer().substr(i + p, this->getBuffer().length() - i - p));
            this->addLine(user_input);
            i = 0;
            l = this->getBuffer().length();
            continue ;
        }
        i++;
    }
}

void abstract_vm::Client::addLine(const std::string& line)
{
    (void) line;
}

void abstract_vm::Client::addBuffer(const std::string& buffer)
{
    this->_buffer += buffer;
    this->checkLine();
}
