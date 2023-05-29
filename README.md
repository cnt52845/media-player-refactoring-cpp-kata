# Media Player Refactoring C++ Kata

[![CI](https://github.com/Coding-Cuddles/media-player-refactoring-cpp-kata/actions/workflows/main.yml/badge.svg)](https://github.com/Coding-Cuddles/media-player-refactoring-cpp-kata/actions/workflows/main.yml)
[![Replit](https://replit.com/badge?caption=Try%20with%20Replit&variant=small)](https://replit.com/new/github/Coding-Cuddles/media-player-refactoring-cpp-kata)

## Overview

This kata complements [Clean Code: SOLID, Ep. 12 - Interface Segregation Principle](https://cleancoders.com/episode/clean-code-episode-12).

The exercise involves refactoring a multimedia player system to adhere to this
principle.

The problem we have at hand involves different types of media -- audio, video,
and images. We start with a monolithic `IMediaPlayer` interface that handles
all types of media. This will be your starting point.

## Instructions

### Exercise 1

In the first part, your task is to refactor the existing code such that each
type of media player (audio, video, and image) has its own specific interface,
instead of the monolithic `IMediaPlayer` interface. You should create
`IAudioPlayer`, `IVideoPlayer`, and `IImageViewer` interfaces, each with a
relevant method, and update the `AudioPlayer`, `VideoPlayer`, and `ImagePlayer`
classes to implement these new interfaces.

This part includes unit tests that ensure each type of media player is
functioning correctly. After you have completed your refactoring, all unit
tests should pass.

### Exercise 2

In the advanced part, we introduce a more complex scenario. Media files come in
different formats, and not all players can handle all formats. Firstly, you
will have to add the `MediaFile` class to represent a media file:

```cpp
class MediaFile {
public:
    std::string format;
    std::string fileName;
};
```

Next, your task is to:

1. Update the player interfaces and classes to handle `MediaFile` objects.
   For example, the `IAudioPlayer` interface becomes:

    ```cpp
    class IAudioPlayer {
    public:
        virtual void play_audio(const MediaFile& file) = 0;
    };
    ```

2. Create specialized players that can only handle certain formats (e.g.,
   `Mp3Player`, `FlacPlayer`, `WavPlayer`).

   ```cpp
   class Mp3Player : public IAudioPlayer {
   public:
       void play_audio(const MediaFile& file) override {
           if (file.format != "mp3") {
               throw std::invalid_argument("Invalid file format for Mp3Player!");
           }
           // Implementation...
       }
   };
   ```

   The same kind of specialization will be done for `FlacPlayer`, `WavPlayer`,
   and respective video and image players.

3. Refactor the `MediaListPlayer` class to work with the new player interfaces
   and classes. This class accepts a list of media files and a corresponding
   list of players. It checks if the player is compatible with the media file
   format before trying to play/display the file.

   Notice that `IMediaPlayer` interface now has a play method which accepts
   MediaFile. This method will call the appropriate method depending on the
   player type (e.g., playAudio, displayVideo, viewImage).

   Your task is to refactor the code to segregate interfaces based on the
   different file formats and adapt the `MediaListPlayer` to work with the new
   classes and interfaces.

This part includes additional unit tests for the new player classes and the
`MediaListPlayer` class. After refactoring, all unit tests should pass.

## Usage

You can import this project into [Replit](https://replit.com),
and it will handle all dependencies automatically.

### Prerequisites

* [CMake 3.19+](https://cmake.org)
* [Ninja](https://ninja-build.org)
* [GTest](https://github.com/google/googletest)

### Build

```console
make
```

### Run main

```console
make run
```

### Run tests

```console
make test
```
