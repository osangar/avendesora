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

#include "window.h"
#include <stdexcept>

NativeWindow::NativeWindow() : display(XOpenDisplay(nullptr)) {
  if (display == nullptr) {
    throw std::runtime_error("XOpenDisplay() failed.");
  }

  screen = DefaultScreen(display);

  window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10,
                               640, 480, 1, BlackPixel(display, screen),
                               BlackPixel(display, screen));

  XStoreName(display, window, "avendesora");

  XSelectInput(display, window, ExposureMask);
  XMapWindow(display, window);
}

NativeWindow::~NativeWindow() noexcept { XCloseDisplay(display); }

/// Processes events relavent to the native window.
auto NativeWindow::process_events() noexcept -> void {
  XEvent event;
  XNextEvent(display, &event);
}