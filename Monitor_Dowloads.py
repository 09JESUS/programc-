import os
import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import subprocess

class FileHandler(FileSystemEventHandler):
    def on_created(self, event):
        # Run your file organizer script when a new file is created
        if not event.is_directory:
            print(f"New file created: {event.src_path}")
            subprocess.run(["python", "C:/Users/forge/OneDrive/Desktop/Projects/python/file_organizer.py"])

if __name__ == "__main__":
    #write your download path to your laptop
    downloads_folder = "C:/Users/forge/Downloads"

    event_handler = FileHandler()
    observer = Observer()
    observer.schedule(event_handler, downloads_folder, recursive=False)
    observer.start()

    try:
        while True:
            time.sleep(2)
    except KeyboardInterrupt:
        observer.stop()
        observer.join()
