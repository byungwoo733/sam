// Copyright (c) 2012-2018 LG Electronics, Inc.
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

#ifndef WEBAPP_LIFE_HANDLER_H_
#define WEBAPP_LIFE_HANDLER_H_

#include <luna-service2/lunaservice.h>

#include "core/lifecycle/life_handler/life_handler_interface.h"

class WebAppLifeHandler: public AppLifeHandlerInterface
{
public:
    WebAppLifeHandler();
    virtual ~WebAppLifeHandler();

    virtual void launch(AppLaunchingItemPtr item);
    virtual void close(AppCloseItemPtr item, std::string& err_text);
    virtual void pause(const std::string& app_id, const pbnjson::JValue& params,
                        std::string& err_text, bool send_life_event = true);
    virtual void clear_handling_item(const std::string& app_id);

    boost::signals2::signal<void ()> signal_service_disconnected;
    boost::signals2::signal<void (const std::string& app_id, const std::string& uid, const RuntimeStatus& life_status)> signal_app_life_status_changed;
    boost::signals2::signal<void (const std::string& app_id, const std::string& pid, const std::string& webprocid)> signal_running_app_added;
    boost::signals2::signal<void (const std::string& app_id)> signal_running_app_removed;
    boost::signals2::signal<void (const std::string& uid)> signal_launching_done;

private:
    void on_service_ready();
    void on_wam_service_status_changed(bool connection);

    static bool cb_wam_subscription_runninglist(LSHandle* handle, LSMessage* lsmsg, void* user_data);
    static bool cb_return_for_launch_request(LSHandle* handle, LSMessage* lsmsg, void* user_data);
    static bool cb_return_for_close_request(LSHandle* handle, LSMessage* lsmsg, void* user_data);
    static bool cb_return_for_pause_request(LSHandle* handle, LSMessage* lsmsg, void* user_data);
    void handle_running_list_change(const pbnjson::JValue& new_list);
    void subscribe_wam_running_list();

    AppLaunchingItemPtr get_lscall_request_item_by_token(const LSMessageToken& token);
    void remove_item_from_lscall_request_list(const std::string& uid);
    void add_loading_app(const std::string& app_id);
    void remove_loading_app(const std::string& app_id);
    bool is_loading(const std::string& app_id);

    LSMessageToken m_wam_subscription_token;
    pbnjson::JValue m_running_list;
    AppLaunchingItemList m_lscall_request_list;
    std::vector<std::string> m_loading_list;
};

#endif
