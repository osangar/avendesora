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

#include "window.h"

/// Defines the main object for handling platform specific details. It emits
/// signals when keyboard or joystick input has been detected, and handles
/// native window details.
class NativePlatform {
public:
  NativePlatform();

  /// Processes all events.
  auto process_events() noexcept -> void;

private:
  NativeWindow window;
};