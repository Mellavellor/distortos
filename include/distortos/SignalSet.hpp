/**
 * \file
 * \brief SignalSet class header
 *
 * \author Copyright (C) 2015 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \date 2015-02-05
 */

#ifndef INCLUDE_DISTORTOS_SIGNALSET_HPP_
#define INCLUDE_DISTORTOS_SIGNALSET_HPP_

#include <bitset>

namespace distortos
{

/**
 * \brief SignalSet class is used as a set of signals.
 *
 * Similar to POSIX sigset_t - http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/signal.h.html
 */

class SignalSet
{
public:

	/// tag struct to construct empty SignalSet
	struct Empty
	{

	};

	/// tag struct to construct full SignalSet
	struct Full
	{

	};

	/// tag object to construct empty SignalSet
	constexpr static Empty empty = {};

	/// tag object to construct full SignalSet
	constexpr static Full full = {};

	/**
	 * \brief SignalSet's constructor
	 *
	 * \param [in] bitmask is the bit mask used to initialize internal bitset
	 */

	constexpr explicit SignalSet(uint32_t bitmask) :
			bitset_{bitmask}
	{

	}

	/**
	 * \brief SignalSet's constructor
	 *
	 * Constructs empty SignalSet.
	 *
	 * Similar to sigemptyset() - http://pubs.opengroup.org/onlinepubs/9699919799/functions/sigemptyset.html#
	 */

	constexpr explicit SignalSet(const Empty&) :
			SignalSet{uint32_t{}}
	{

	}

	/**
	 * \brief SignalSet's constructor
	 *
	 * Constructs full SignalSet.
	 *
	 * Similar to sigfillset() - http://pubs.opengroup.org/onlinepubs/9699919799/functions/sigfillset.html#
	 */

	constexpr explicit SignalSet(const Full&) :
			SignalSet{~uint32_t{}}
	{

	}

private:

	/// internal bitset for 32 signals
	std::bitset<32> bitset_;
};

}	// namespace distortos

#endif	// INCLUDE_DISTORTOS_SIGNALSET_HPP_