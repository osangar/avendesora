# This file is part of avendesora.
#
# avendesora is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# avendesora is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# avendesora.  If not, see <https://www.gnu.org/licenses/>.

# We always want to compile the components for the system cores and the system
# cores themselves...
add_subdirectory(system)

# ...before the frontend.
add_subdirectory(app)