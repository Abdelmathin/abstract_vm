/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:    */
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
#include "Instruction.hpp"
#include <vector>
#include <iostream>

namespace abstract_vm
{
	class Parser
	{
		private:
			unsigned int                            _tpos;
			std::vector< abstract_vm::Token >       _tokens;
			std::vector< abstract_vm::Instruction > _instructions;
			void init(void);
		public:
			Parser(void);
			~Parser(void);
			Parser(const Parser& other);
			Parser& operator=(const Parser& other);

			bool               advance(void);
			abstract_vm::Token currentToken(void);
			bool               skipBlankTokens(void);
			bool               syntaxError(void);
			bool               pushInt8(void);
			bool               pushInt16(void);
			bool               pushInt32(void);
			bool               pushInt64(void);
			bool               pushFloat(void);
			bool               pushDouble(void);
			bool               pushImage(void);
			bool               pushInstruction(void);

			void setTokens(const std::vector< abstract_vm::Token >& tokens);
			void parse(void);
			void clear(void);
	};
}
