# ENGINEGURU 0.2.0

JUCE 8.0.6 VST3/Standalone source project for Windows and FL Studio.

## Six-module interface foundation
- **DYNAMICS** — compressor and de-esser control surface.
- **TONE** — four-band EQ and filters control surface.
- **SPACE** — reverb and delay control surface.
- **SFX** — pitch and stereo-width control surface.
- **GENERATOR** — retained deterministic 16-variation drum synthesis workflow.
- **ANALYZER** — retained WAV/AIFF sample loading and heuristic analysis.

**Important implementation status:** this source baseline contains the six-module visual layout, but Dynamics, Tone, Space and SFX are not yet connected to effect DSP or host-automatable parameters. The current `processBlock` clears the output buffer, so this is not yet a functioning audio-effect plugin. The Generator and Analyzer workflows remain available through the existing editor actions and DSP sources. This ZIP is a source/UI milestone, not a verified finished VST3.

## Preserved foundation
- Existing `DrumSynth` and `SampleAnalyzer` source files.
- Similarity and Amount generator parameters.
- WAV/AIFF reference loading (up to 8 seconds).
- Deterministic 16-variation synthesis and 24-bit WAV export.
- JUCE 8.0.6 FetchContent pin and JUCE header-generation setup.

## Windows build
Install Visual Studio 2022 with Desktop development with C++, Windows SDK, CMake 3.22+, and Git. From this directory:

```powershell
cmake -S . -B build -A x64
cmake --build build --config Release --target ENGINEGURU_VST3
```

The VST3 bundle is produced at `build/ENGINEGURU_artefacts/Release/VST3`.

## GitHub Actions
Push to `main`, or manually run Actions → Build ENGINEGURU VST3 → Run workflow. The workflow uploads `ENGINEGURU-0.2.0-VST3-Windows` as an artifact.

## Engineering status
The analyzer uses time-domain heuristics rather than full FFT/pitch-envelope analysis; sound models need listening-based tuning. A successful build is not claimed until GitHub Actions passes.
