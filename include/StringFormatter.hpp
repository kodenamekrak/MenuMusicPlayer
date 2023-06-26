#pragma once

namespace MenuMusicPlayer::StringFormatter {
    inline std::string TimeFormat(int time)
    {
        int minutes = time / 60;
        int seconds = time % 60;
        std::string str = std::to_string(minutes) + ":";
        if(seconds < 10)
            str += "0";
        str += std::to_string(seconds);
        return str;
    }
}