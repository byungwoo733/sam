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

#ifndef APPSCAN_FILTER_4_BASE_H
#define APPSCAN_FILTER_4_BASE_H

#include "interface/package/appscan_filter_interface.h"

class AppScanFilter4Base: public AppScanFilterInterface {
public:
  AppScanFilter4Base();
  virtual ~AppScanFilter4Base();

  virtual bool ValidatePreCondition();
  virtual bool ValidatePostCondition(AppTypeByDir type_by_dir, AppDescPtr app_desc);
};

#endif // APPSCAN_FILTER_4_BASE_H

