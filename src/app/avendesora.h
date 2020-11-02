// This file is part of avendesora.
//
// avendesora is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// avendesora is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// avendesora.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "platform/platform.h"

// Main application object.
class Avendesora {
public:
  Avendesora() noexcept;

  // Starts the application.
  auto run() noexcept -> int;

private:
  // Determines whether or not the application is running.
  bool is_running{true};

  // Native platform instance; emits signals when keyboard/joystick events take
  // place.
  NativePlatform platform;
};