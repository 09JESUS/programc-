import os
import shutil
#create a function that receive 2 argument (1-Source directives,2-target_directives)
def organize_files(source_dir, target_dir):
    try:
        # Check if target directory exists, if not create it
        if not os.path.exists(target_dir):
            os.makedirs(target_dir)

        # Iterate over all files in the source directory
        for filename in os.listdir(source_dir):
            source_file = os.path.join(source_dir, filename)
            
            # Check if the path is a file and not a directory
            if os.path.isfile(source_file):
                # Get the file extension
                file_extension = os.path.splitext(filename)[1]

                # Move the file to the target directory
                target_file = os.path.join(target_dir, filename)
                shutil.move(source_file, target_file)
                print(f"Moved: {source_file} to {target_file}")

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    source_dir = r"C:\Users\forge\Downloads"  # Update this path
    target_dir = r"C:\Users\forge\Desktop\Organized"  # Update this path if necessary

    organize_files(source_dir, target_dir)
