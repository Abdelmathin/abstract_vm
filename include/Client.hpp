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

#pragma once

#include "abstract_vm.hpp"
#include "OStream.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "VirtualMachine.hpp"
#include <iostream>

namespace abstract_vm
{
    class Client
    {
        private:
            int                         _fdin         ;
            int                         _fdout        ;
            int                         _fderr        ;
            bool                        _connected    ;
            std::string                 _buffer       ;
            std::string                 _eos          ;
            abstract_vm::OStream        _outputstream ;
            abstract_vm::OStream        _errorstream  ;
            abstract_vm::Lexer          _lexer        ;
            abstract_vm::Parser         _parser       ;
            abstract_vm::VirtualMachine _vm           ;
            void init(void)                           ;
        public:
            Client(void);
            ~Client(void);
            Client(const Client& other);
            Client& operator=(const Client& other);

            int                          getFdIn(void)         const;
            int                          getFdOut(void)        const;
            int                          getFdErr(void)        const;
            bool                         isConnected(void)     const;
            std::string                  getBuffer(void)       const;
            std::string                  getEOS(void)          const;

            void                         setFdIn(int fdin)                                   ;
            void                         setFdOut(int fdout)                                 ;
            void                         setFdErr(int fderr)                                 ;
            void                         setConnected(bool status)                            ;
            void                         setBuffer(const std::string& buffer)                       ;
            void                         setEOS(const std::string& eos)                             ;
            void                         setOutputstream(const abstract_vm::OStream& stream) ;
            void                         setErrorstream(const abstract_vm::OStream& stream)  ;
            void                         setLexer(const abstract_vm::Lexer& lexer)           ;
            void                         setParser(const abstract_vm::Parser& parser)        ;
            void                         setVm(const abstract_vm::VirtualMachine& vm)        ;

            void                         clear(void);
            int                          read(void);
            void                         checkLine(void);
            void                         addLine(const std::string& line);
            void                         addBuffer(const std::string& buffer);
    };
}
