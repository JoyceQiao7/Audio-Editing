import librosa
import soundfile as sf
import numpy as np
import tkinter as tk
from tkinter import filedialog


def load_audio_files():
    root = tk.Tk()
    root.withdraw()  # Hide the root window
    file_paths = filedialog.askopenfilenames(title="Select audio files",
                                             filetypes=[("Audio Files", "*.wav *.mp3 *.flac *.ogg")])
    audio_files = []
    for path in file_paths:
        try:
            audio, sr = librosa.load(path, sr=None)
            audio_files.append((audio, sr))
        except FileNotFoundError:
            print(f"File not found: {path}")
        except Exception as e:
            print(f"An error occurred while loading {path}: {e}")
    return audio_files


def save_audio(audio, sr, path):
    try:
        sf.write(path, audio, sr)
        print(f"Audio saved to {path}")
    except Exception as e:
        print(f"An error occurred while saving the file: {e}")


print("Please select two audio files to process:")

# Load audio files
audio_files = load_audio_files()

# Ensure there are at least two audio files
if len(audio_files) < 2:
    print("Please provide at least two audio files.")
    exit()

# Step 1: Create Track1 by concatenating the first and second audio files
audio1, sr1 = audio_files[0]
audio2, sr2 = audio_files[1]
# print(sr1, sr2)

if sr1 != sr2:
    print("Sample rates of the audio files do not match. Please provide audio files with the same sample rate.")
    exit()

track1 = np.concatenate((audio1, audio2))

# Save Track1
track1_path = filedialog.asksaveasfilename(title="Save Track1", defaultextension=".wav",
                                           filetypes=[("WAV files", "*.wav")])
if track1_path:
    save_audio(track1, sr1, track1_path)

# Step 2: Cut the two audio files into two short clips, each for 10 seconds
# clip_length1 = int(input("How many seconds do you want for the first audio file: ").strip())
# clip_length2 = int(input("How many seconds do you want for the second audio file: ").strip())
clip_length = sr1 * 10
track2 = audio1[:clip_length]
track3 = audio2[:clip_length]

# Save Track2 and Track3
track2_path = filedialog.asksaveasfilename(title="Save Track2", defaultextension=".wav",
                                           filetypes=[("WAV files", "*.wav")])
if track2_path:
    save_audio(track2, sr1, track2_path)

track3_path = filedialog.asksaveasfilename(title="Save Track3", defaultextension=".wav",
                                           filetypes=[("WAV files", "*.wav")])
if track3_path:
    save_audio(track3, sr1, track3_path)

# Step 3: Create Track4 by concatenating Track2 and Track3
track4 = np.concatenate((track2, track3))

# Save Track4
track4_path = filedialog.asksaveasfilename(title="Save Track4", defaultextension=".wav",
                                           filetypes=[("WAV files", "*.wav")])
if track4_path:
    save_audio(track4, sr1, track4_path)
