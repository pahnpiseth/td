//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2018
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/utils/port/config.h"

#include "td/utils/common.h"
#include "td/utils/Slice.h"
#include "td/utils/Status.h"

namespace td {

struct Stat {
  bool is_dir_;
  bool is_reg_;
  int64 size_;
  uint64 atime_nsec_;
  uint64 mtime_nsec_;
};

Result<Stat> stat(CSlice path) TD_WARN_UNUSED_RESULT;

#if TD_PORT_POSIX

namespace detail {
Stat fstat(int native_fd);  // TODO return Result<Stat>
}  // namespace detail

Status update_atime(CSlice path) TD_WARN_UNUSED_RESULT;

struct MemStat {
  uint64 resident_size_;
  uint64 resident_size_peak_;
  uint64 virtual_size_;
  uint64 virtual_size_peak_;
};

Result<MemStat> mem_stat() TD_WARN_UNUSED_RESULT;

#endif

}  // namespace td
