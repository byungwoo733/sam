// Copyright (c) 2017-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef PRELAUNCHER_STAGES_4_BASE_H
#define PRELAUNCHER_STAGES_4_BASE_H

#include <pbnjson.hpp>

#include "extensions/webos_base/lifecycle/app_launching_item_4_base.h"

bool set_prelaunching_stages_4_base(AppLaunchingItem4BasePtr item);
StageHandlerReturn4Base handle_execution_lock_status(AppLaunchingItem4BasePtr prelaunching_item);

#endif
