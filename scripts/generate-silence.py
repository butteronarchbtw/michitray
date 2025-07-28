from pydub import AudioSegment

silence = AudioSegment.silent(duration=1000)
silence.export("mp3/silence.mp3", format="mp3")
