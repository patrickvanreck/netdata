// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef NETDATA_EVENT_LOOP_H
#define NETDATA_EVENT_LOOP_H

enum event_loop_job {
    UV_EVENT_JOB_NONE = 0,

    // generic
    UV_EVENT_WORKER_INIT,

    // query related
    UV_EVENT_DBENGINE_QUERY,
    UV_EVENT_DBENGINE_EXTENT_CACHE_LOOKUP,
    UV_EVENT_DBENGINE_EXTENT_MMAP,
    UV_EVENT_DBENGINE_EXTENT_DECOMPRESSION,
    UV_EVENT_DBENGINE_EXTENT_PAGE_LOOKUP,
    UV_EVENT_DBENGINE_EXTENT_PAGE_POPULATION,

    // flushing related
    UV_EVENT_DBENGINE_FLUSH_MAIN_CACHE,
    UV_EVENT_DBENGINE_EXTENT_WRITE,
    UV_EVENT_DBENGINE_FLUSHED_TO_OPEN,

    // datafile full
    UV_EVENT_DBENGINE_JOURNAL_INDEX_WAIT,
    UV_EVENT_DBENGINE_JOURNAL_INDEX,

    // db rotation related
    UV_EVENT_DBENGINE_DATAFILE_DELETE_WAIT,
    UV_EVENT_DBENGINE_DATAFILE_DELETE,
    UV_EVENT_DBENGINE_FIND_ROTATED_METRICS, // find the metrics that are rotated
    UV_EVENT_DBENGINE_FIND_REMAINING_RETENTION, // find their remaining retention
    UV_EVENT_DBENGINE_POPULATE_MRG, // update mrg

    // other dbengine events
    UV_EVENT_DBENGINE_EVICT_MAIN_CACHE,
    UV_EVENT_DBENGINE_BUFFERS_CLEANUP,
    UV_EVENT_DBENGINE_QUIESCE,
    UV_EVENT_DBENGINE_SHUTDOWN,

    // metadata
    UV_EVENT_METADATA_STORE,
    UV_EVENT_METADATA_CLEANUP,

    // netdatacli
    UV_EVENT_SCHEDULE_CMD,
};

void register_libuv_worker_jobs();

#endif //NETDATA_EVENT_LOOP_H
