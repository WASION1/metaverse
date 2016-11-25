/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-explorer.
 *
 * libbitcoin-explorer is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/explorer/commands/sha160.hpp>

#include <iostream>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/explorer/define.hpp>

namespace libbitcoin{ 
namespace explorer {

using namespace bc;
using namespace bc::config;
using namespace bc::explorer;
using namespace bc::explorer::commands;

console_result sha160::invoke(std::ostream& output, std::ostream& error)
{
    // Bound parameters.
    const data_chunk& data = get_base16_argument();

    const auto hash = sha1_hash(data);

    output << base16(hash) << std::flush;
    return console_result::okay;
}
}
}
