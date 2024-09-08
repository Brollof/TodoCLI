#pragma once

#include <string>
#include <iostream>
#include <chrono>

class Time
{
public:
    static uint32_t GetNow()
    {
        const auto now = std::chrono::system_clock::now();
        const auto now_s = std::chrono::time_point_cast<std::chrono::seconds>(now);
        return now_s.time_since_epoch().count();
    }

    static std::string GetTimeStringUntilNow(uint32_t time)
    {
        Timepoint tpNow = EpochToTimepoint(GetNow());
        Timepoint tpOld = EpochToTimepoint(time);

        auto diff = tpNow - tpOld;

        uint64_t days = std::chrono::duration_cast<std::chrono::days>(diff).count();
        if (days == 1)  return "1 day ago";
        if (days > 1) return std::to_string(days) + " days ago";

        uint64_t hours = std::chrono::duration_cast<std::chrono::hours>(diff).count();
        if (hours == 1) return "1 hour ago";
        if (hours > 1) return std::to_string(hours) + " hours ago";

        uint64_t minutes = std::chrono::duration_cast<std::chrono::minutes>(diff).count();
        if (minutes == 1) return "1 minute ago";
        if (minutes > 1) return std::to_string(minutes) + " minutes ago";

        uint64_t seconds = std::chrono::duration_cast<std::chrono::seconds>(diff).count();
        if (seconds == 1) return "1 second ago";
        if (seconds > 1) return std::to_string(seconds) + " seconds ago";

        return "just now";
    }

private:
    using Timepoint = std::chrono::time_point<std::chrono::system_clock>;

    Time();

    static Timepoint EpochToTimepoint(uint32_t epoch)
    {
        std::chrono::seconds dur(epoch);
        return Timepoint(dur);
    }

    static void PrintTimepoint(const Timepoint &tp)
    {

        const time_t startWallTime = std::chrono::system_clock::to_time_t(tp);
        std::cout << ctime(&startWallTime) << std::endl;
    }
};
