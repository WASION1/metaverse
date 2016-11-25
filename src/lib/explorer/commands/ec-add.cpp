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
#include <bitcoin/explorer/commands/ec-add.hpp>

#include <iostream>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/explorer/define.hpp>

namespace libbitcoin{ 
namespace explorer {

using namespace bc;
using namespace bc::explorer;
using namespace bc::explorer::commands;
using namespace bc::wallet;

console_result ec_add::invoke(std::ostream& output, std::ostream& error)
{
    // Bound parameters.
    const auto& point = get_point_argument();
    const auto& secret = get_secret_argument();
    
    // Create a copy of the public key.
    ec_compressed sum(point);

    // Elliptic curve function POINT + (INTEGER * curve-generator-point).
    if (!bc::ec_add(sum, secret))
    {
        error << BX_EC_ADD_OUT_OF_RANGE << std::flush;
        return console_result::failure;
    }

    // Serialize to the original compression state.
    output << ec_public(sum, point.compressed()) << std::flush;
    return console_result::okay;
}
}
}
