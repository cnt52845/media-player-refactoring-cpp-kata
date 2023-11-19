#pragma once

#include <stdexcept>
#include <string>

class MediaFile {
public:
    std::string format;
    std::string filename;
};

class IMediaPlayer {
public:
    virtual void play_audio()    = 0;
    virtual void display_video() = 0;
    virtual void view_image()    = 0;
};

class IAudioPlayer {
public:
    virtual void play_audio(const MediaFile& file) = 0;
};

class IVideoPlayer {
public:
    virtual void display_video(const MediaFile& file) = 0;
};

class IImageViewer {
public:
    virtual void view_image(const MediaFile& file) = 0;
};

class Mp3Player : public IAudioPlayer {
public:
    void play_audio(const MediaFile& file) final
    {
        if (file.format != "mp3") {
            throw std::invalid_argument("Invalid file format for Mp3Player!");
        }
        // Implementation...
    }
};

class FlacPlayer : public IAudioPlayer {
public:
    void play_audio(const MediaFile& file) final
    {
        if (file.format != "flac") {
            throw std::invalid_argument("Invalid file format for FlacPlayer!");
        }
        // Implementation...
    }
};

class WavPlayer : public IAudioPlayer {
public:
    void play_audio(const MediaFile& file) final
    {
        if (file.format != "wav") {
            throw std::invalid_argument("Invalid file format for WavPlayer!");
        }
        // Implementation...
    }
};

class JpgPlayer : public IImageViewer {
public:
    void view_image(const MediaFile& file) final
    {
        if (file.format != "jpg") {
            throw std::invalid_argument("Invalid file format for JpgPlayer!");
        }
        // Implementation...
    }
};

class PngPlayer : public IImageViewer {
public:
    void view_image(const MediaFile& file) final
    {
        if (file.format != "png") {
            throw std::invalid_argument("Invalid file format for PngPlayer!");
        }
        // Implementation...
    }
};

class Mp4Player : public IVideoPlayer {
public:
    void display_video(const MediaFile& file) final
    {
        if (file.format != "mp4") {
            throw std::invalid_argument("Invalid file format for PngPlayer!");
        }
        // Implementation...
    }
};
/*
using AudioPlayers = std::vector<std::shared_ptr<IAudioPlayer>>;
using VideoPlayers = std::vector<std::shared_ptr<IVideoPlayer>>;
using ImagePlayers = std::vector<std::shared_ptr<IImagePlayer>>;
*/
struct Players {
    std::map<std::string, std::shared_ptr<IAudioPlayer>> audio_players;
    std::map<std::string, std::shared_ptr<IVideoPlayer>> video_players;
    std::map<std::string, std::shared_ptr<IImageViewer>> image_players;
};

class MediaListPlayer {
public:
    void play_list(const std::vector<MediaFile>& media_list, const Players& players)
    {
        for (const MediaFile& file : media_list) {
            auto audio_player = players.audio_players.find(file.format);
            if (audio_player != players.audio_players.end()) {
                audio_player->second->play_audio(file);
                continue;
            }
            auto video_player = players.video_players.find(file.format);
            if (video_player != players.video_players.end()) {
                video_player->second->display_video(file);
                continue;
            }
            throw std::invalid_argument("Invalid file format!");
        }
    }
};
