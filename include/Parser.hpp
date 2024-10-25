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
#include "IOperand.hpp"
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

			IOperand const * createOperand( eOperandType type, std::string const & value ) const;
			IOperand const * createInt8(   std::string const & value ) const;
			IOperand const * createInt16(  std::string const & value ) const;
			IOperand const * createInt32(  std::string const & value ) const;
			IOperand const * createFloat(  std::string const & value ) const;
			IOperand const * createDouble( std::string const & value ) const;

			bool               advance(void);
			abstract_vm::Token currentToken(void);
			bool               skipBlankTokens(void);
			bool               skipEmptyTokens(void);
			bool               skipWhiteTokens(void);
			bool               syntaxError(void);
			bool               push(void);
			bool               addInstruction(void);
			bool               mulInstruction(void);
			bool               dumpInstruction(void);
			bool               popInstruction(void);
			bool               exitInstruction(void);
			bool               printInstruction(void);

			void setTokens(const std::vector< abstract_vm::Token >& tokens);
			void parse(void);
			void clear(void);
	};
}
