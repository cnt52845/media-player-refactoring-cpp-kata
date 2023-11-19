#include <gmock/gmock.h>
#include <stdexcept>

#include "media_player.h"

TEST(AudioPlayerTest, Mp3PlayerHandlesMp3)
{
    Mp3Player mp3_player;
    MediaFile mp3_file;
    mp3_file.format = "mp3";
    EXPECT_NO_THROW(mp3_player.play_audio(mp3_file));
}

TEST(AudioPlayerTest, Mp3PlayerRejectsNonMp3)
{
    Mp3Player mp3_player;
    MediaFile flac_file;
    flac_file.format = "flac";
    EXPECT_THROW(mp3_player.play_audio(flac_file), std::invalid_argument);
}

TEST(AudioPlayerTest, FlacPlayerHandlesFlac)
{
    FlacPlayer flac_player;
    MediaFile  flac_file;
    flac_file.format = "flac";
    EXPECT_NO_THROW(flac_player.play_audio(flac_file));
}

TEST(AudioPlayerTest, FlacPlayerRejectsNonFlac)
{
    FlacPlayer flac_player;
    MediaFile  mp3_file;
    mp3_file.format = "mp3";
    EXPECT_THROW(flac_player.play_audio(mp3_file), std::invalid_argument);
}

TEST(AudioPlayerTest, WavPlayerHandlesWav)
{
    WavPlayer wav_player;
    MediaFile wav_file;
    wav_file.format = "wav";
    EXPECT_NO_THROW(wav_player.play_audio(wav_file));
}

TEST(AudioPlayerTest, WavPlayerRejectsNonWav)
{
    WavPlayer wav_player;
    MediaFile mp3_file;
    mp3_file.format = "mp3";
    EXPECT_THROW(wav_player.play_audio(mp3_file), std::invalid_argument);
}

TEST(ImagePlayerTest, JpgPlayerHandlesJpg)
{
    JpgPlayer jpg_player;
    MediaFile media_file;
    media_file.format = "jpg";
    EXPECT_NO_THROW(jpg_player.view_image(media_file));
}

TEST(ImagePlayerTest, JpgPlayerRejectsNonJpg)
{
    JpgPlayer jpg_player;
    MediaFile media_file;
    media_file.format = "png";
    EXPECT_THROW(jpg_player.view_image(media_file), std::invalid_argument);
}

TEST(ImagePlayerTest, PngPlayerHandlesJPng)
{
    PngPlayer png_player;
    MediaFile media_file;
    media_file.format = "png";
    EXPECT_NO_THROW(png_player.view_image(media_file));
}

TEST(ImagePlayerTest, PngPlayerRejectsNonPng)
{
    PngPlayer png_player;
    MediaFile media_file;
    media_file.format = "jpg";
    EXPECT_THROW(png_player.view_image(media_file), std::invalid_argument);
}

TEST(VideoPlayerTest, Mp4PlayerHandlesMp4)
{
    Mp4Player mp4_player;
    MediaFile media_file;
    media_file.format = "mp4";
    EXPECT_NO_THROW(mp4_player.display_video(media_file));
}

TEST(VideoPlayerTest, Mp4PlayerRejectsNonMp4)
{
    Mp4Player mp4_player;
    MediaFile media_file;
    media_file.format = "mkv";
    EXPECT_THROW(mp4_player.display_video(media_file), std::invalid_argument);
}

TEST(MediaListPlayerTest, MediaListPlayerPlaysCompatibleList)
{
    std::vector<MediaFile> media_list{
        {"mp3", "file.mp3"}, {"wav", "file.wav"}, {"mp4", "file.mp4"}};
    Players players{.audio_players{
                        {"mp3", std::make_shared<Mp3Player>()},
                        {"wav", std::make_shared<WavPlayer>()},
                    },

                    .video_players{{"mp4", std::make_shared<Mp4Player>()}}};

    // AudioPlayers players{new Mp3Player(), new FlacPlayer(), new WavPlayer()};

    MediaListPlayer list_player;
    // AudioListPlayer list_player;

    EXPECT_NO_THROW(list_player.play_list(media_list, players));
}
