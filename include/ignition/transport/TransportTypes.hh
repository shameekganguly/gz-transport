/*
 * Copyright (C) 2014 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _IGN_TRANSPORT_TRANSPORTTYPES_HH_INCLUDED__
#define _IGN_TRANSPORT_TRANSPORTTYPES_HH_INCLUDED__

#include <google/protobuf/message.h>
#include <map>
#include <memory>
#include <string>
#include <thread>
#include <vector>

/// \file
/// \ingroup ignition_transport
/// \brief Forward declarations for transport
namespace ignition
{
  namespace transport
  {
    class ISubscriptionHandler;
    class NodePrivate;
    class TopicInfo;

    /// \def Topics_L
    /// \brief List of topics.
    typedef std::vector<std::string> Topics_L;

    typedef google::protobuf::Message ProtoMsg;

    /// \def ProtoMsgPtr
    /// \brief Shared pointer to any protobuf message.
    typedef std::shared_ptr<ProtoMsg> ProtoMsgPtr;

    /// \def ReqCallback
    /// \brief Callback used for receiving a service call request.
    typedef std::function<void (const std::string &, int,
                                const std::string &)> ReqCallback;

    /// \def RepCallback
    /// \brief Callback used for receving a service call response.
    typedef std::function<int (const std::string &,
                               const std::string &,
                               std::string &)> RepCallback;

    /// \def Topics_M
    /// \brief Map used for store all the knowledge about a given topic.
    typedef std::map<std::string, std::shared_ptr<TopicInfo>> Topics_M;

    /// \def NodePrivatePtr
    /// \brief Shared pointer to NodePrivate.
    typedef std::shared_ptr<transport::NodePrivate> NodePrivatePtr;

    /// \def SubscriptionHandlerPtr
    /// \brief Shared pointer to ISubscriptionHandler.
    typedef std::shared_ptr<ISubscriptionHandler> ISubscriptionHandlerPtr;

    /// \def ISubscriptionHandler_M
    /// \brief Map to store the different subscription handlers for a topic.
    /// Each thread can have its own subscription handler. The thread id
    /// is used as key.
    typedef std::map<std::thread::id, ISubscriptionHandlerPtr>
        ISubscriptionHandler_M;
  }
}

#endif

