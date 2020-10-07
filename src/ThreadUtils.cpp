/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*-
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "vrb/Logger.h"
#include "vrb/ThreadUtils.h"

#ifndef __APPLE__
#  include <sys/prctl.h>
#endif

namespace vrb {
void SetThreadName(const std::string& aName) {
#ifndef __APPLE__
  prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(aName.c_str()));
#endif
}

} // namespace vrb

