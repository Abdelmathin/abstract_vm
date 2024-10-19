/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:    */
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
#include "Token.hpp"
#include <iostream>
#include <vector>

namespace abstract_vm
{
	class Lexer
	{
		private:
			std::string::size_type            _index;
			std::string                       _buffer;
			std::vector< abstract_vm::Token > _tokens;
			void init(void);
		public:
			Lexer(void);
			~Lexer(void);
			Lexer(const Lexer& other);
			Lexer& operator=(const Lexer& other);

			char                   peek(void)      const ;
			bool                   eof(void)       const ;
			std::string::size_type getIndex(void)  const ;
			std::string            getBuffer(void) const ;

			void                   setIndex(std::string::size_type index) ;
			void                   setBuffer(const std::string& buffer)   ;

			void                   advance(void)    ;
			void                   addComment(void) ;
			void                   addWord(void)    ;
			void                   tokenize(void)   ;
			void                   clear(void)      ;
	};
}
