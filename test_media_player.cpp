#include <gmock/gmock.h>

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

TEST(VideoPlayerTest, Mp4PlayerHandlesMp4)
{
    Mp4Player mp4_player;
    MediaFile mp4_file;
    mp4_file.format = "mp4";
    EXPECT_NO_THROW(mp4_player.display_video(mp4_file));
}

TEST(VideoPlayerTest, Mp4PlayerRejectsNonMp4)
{
    Mp4Player mp4_player;
    MediaFile mkv_file;
    mkv_file.format = "mkv";
    EXPECT_THROW(mp4_player.display_video(mkv_file), std::invalid_argument);
}

TEST(VideoPlayerTest, MkvPlayerHandlesMkv)
{
    MkvPlayer mkv_player;
    MediaFile mkv_file;
    mkv_file.format = "mkv";
    EXPECT_NO_THROW(mkv_player.display_video(mkv_file));
}

TEST(VideoPlayerTest, MkvPlayerRejectsNonMkv)
{
    MkvPlayer mkv_player;
    MediaFile mp4_file;
    mp4_file.format = "mp4";
    EXPECT_THROW(mkv_player.display_video(mp4_file), std::invalid_argument);
}

TEST(ImagePlayerTest, JpegPlayerHandlesJpeg)
{
    JpegPlayer jpeg_player;
    MediaFile  jpeg_file;
    jpeg_file.format = "jpeg";
    EXPECT_NO_THROW(jpeg_player.view_image(jpeg_file));
}

TEST(ImagePlayerTest, JpegPlayerRejectsNonJpeg)
{
    JpegPlayer jpeg_player;
    MediaFile  png_file;
    png_file.format = "png";
    EXPECT_THROW(jpeg_player.view_image(png_file), std::invalid_argument);
}

TEST(ImagePlayerTest, PngPlayerHandlesPng)
{
    PngPlayer png_player;
    MediaFile png_file;
    png_file.format = "png";
    EXPECT_NO_THROW(png_player.view_image(png_file));
}

TEST(ImagePlayerTest, PngPlayerRejectsNonPng)
{
    PngPlayer png_player;
    MediaFile jpeg_file;
    jpeg_file.format = "jpeg";
    EXPECT_THROW(png_player.view_image(jpeg_file), std::invalid_argument);
}

TEST(MediaListPlayerTest, MediaListPlayerPlaysCompatibleList)
{
    std::vector<MediaFile> media_list{/* populate media files */};
    Players                players{/* populate players */};

    MediaListPlayer list_player;
    EXPECT_NO_THROW(list_player.play_list(media_list, players));
}
