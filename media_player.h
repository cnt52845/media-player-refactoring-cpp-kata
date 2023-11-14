#pragma once

#include <stdexcept>
#include <string>
#include <memory>
#include <map>

class MediaFile {
public:
    std::string format;
    std::string filename;
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
    void play_audio(const MediaFile& file) override
    {
        if (file.format != "mp3") {
            throw std::invalid_argument("Invalid file format for Mp3Player!");
        }
        // Implementation...
    }
};

class FlacPlayer : public IAudioPlayer {
public:
    void play_audio(const MediaFile& file) override
    {
        if (file.format != "flac") {
            throw std::invalid_argument("Invalid file format for FlacPlayer!");
        }
        // Implementation...
    }
};

class WavPlayer : public IAudioPlayer {
public:
    void play_audio(const MediaFile& file) override
    {
        if (file.format != "wav") {
            throw std::invalid_argument("Invalid file format for WavPlayer!");
        }
        // Implementation...
    }
};

class Mp4Player : public IVideoPlayer {
public:
    void display_video(const MediaFile& file) override
    {
        if (file.format != "mp4") {
            throw std::invalid_argument("Invalid file format for Mp4Player!");
        }
        // Implementation...
    }
};

class MkvPlayer : public IVideoPlayer {
public:
    void display_video(const MediaFile& file) override
    {
        if (file.format != "mkv") {
            throw std::invalid_argument("Invalid file format for MkvPlayer!");
        }
        // Implementation...
    }
};

class JpegPlayer : public IImageViewer {
public:
    void view_image(const MediaFile& file) final
    {
        if (file.format != "jpeg") {
            throw std::invalid_argument("Invalid file format for JpegPlayer!");
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

class MediaListPlayer {
public:
    using MediaList    = std::vector<MediaFile>;
    using AudioPlayers = std::map<std::string, std::shared_ptr<IAudioPlayer>>;
    using VideoPlayers = std::map<std::string, std::shared_ptr<IVideoPlayer>>;
    using ImagePlayers = std::map<std::string, std::shared_ptr<IImageViewer>>;

    struct Players {
        AudioPlayers audio_players;
        VideoPlayers video_players;
        ImagePlayers image_players;
    };

    void play_list(const MediaList& media_list, const Players& players)
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
            auto image_player = players.image_players.find(file.format);
            if (image_player != players.image_players.end()) {
                image_player->second->view_image(file);
                continue;
            }
            throw std::invalid_argument("Unknown file format!");
        }
    }
};
