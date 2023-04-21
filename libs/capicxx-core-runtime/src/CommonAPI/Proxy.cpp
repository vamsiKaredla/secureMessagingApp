// Copyright (C) 2013-2020 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <CommonAPI/Proxy.hpp>

namespace CommonAPI {

Proxy::~Proxy() {
    completed_.set_value();
}

const Address &
Proxy::getAddress() const {
    return address_;
}

std::future<void> Proxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace CommonAPI
