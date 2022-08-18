#!bin/python3
import os
import sys

from pathlib import Path
from shutil import copyfile

# /var/system/openads
# ├── config
# │   ├── camera
# │   │   └── info
# │   │       ├── associated_ids.xml
# │   │       ├── info.xml
# │   │       └── registered_devices.xml
# │   ├── log
# │   │   └── log_config.yaml
# │   ├── models
# │   │   ├── elephant
# │   │   │   ├── elephant.config
# │   │   │   └── scad_elephantnn_model.pt
# │   │   └── facial
# │   │       └── haarcascade_frontalface_default.xml
# │   └── storage
# │       └── capacity
# ├── execution
# │   └── exec
# └── storage

root_path = '/var/system/openads'
copy_root_path = os.path.abspath('../../configuration')

system_level_dirs = ['config', 'execution', 'storage']
config_sub_dirs = ['camera', 'log', 'models', 'models', 'storage']
sublevel_directories = {
	'config': config_sub_dirs,
	'execution': [],
	'storage': [],
}


def generate_directories():
	print('- Creating directories')
	# Create root dir
	path = Path(root_path)
	path.parent.mkdir(parents=True, exist_ok=True)

	# Setup first level directories
	for sl in system_level_dirs:
		to_generate = os.path.join(root_path, sl)
		print('├── Setting up {}'.format(to_generate))
		os.makedirs(to_generate, exist_ok=True)

		# Setup second level directories
		contains_sub = sublevel_directories[sl]
		if contains_sub:
			for x in contains_sub:
				level_dir = os.path.join(to_generate, x)
				print('    ├── {}'.format(level_dir))
				os.makedirs(level_dir, exist_ok=True)

				if x == 'camera':
					t_level_dir = os.path.join(level_dir, 'info')
					os.makedirs(t_level_dir, exist_ok=True)
					print('        ├── {}'.format(t_level_dir))
				elif x == 'models':
					for d in ['elephant', 'facial']:
						t_level_dir = os.path.join(level_dir, d)
						os.makedirs(t_level_dir, exist_ok=True)
						print('        ├── {}'.format(t_level_dir))


def copy_files():
	mapped_files = [
		# Camera info
		(os.path.join(copy_root_path, 'camera', 'info.xml'), os.path.join(root_path, 'config', 'camera', 'info')),
		# Log
		(os.path.join(copy_root_path, 'log', 'log_config.yaml'), os.path.join(root_path, 'config', 'log')),
		# Execution,
		(os.path.join(copy_root_path, 'execution', 'exec'), os.path.join(root_path, 'execution')),
		# Storage
		(os.path.join(copy_root_path, 'storage', 'capacity'), os.path.join(root_path, 'config', 'storage')),
		# Elephant
		(os.path.join(copy_root_path, 'models', 'elephant.config'),
		 os.path.join(root_path, 'config', 'models', 'elephant')),
		(os.path.join(copy_root_path, 'models', 'scad_elephantnn_model.pt'),
		 os.path.join(root_path, 'config', 'models', 'elephant')),
	]
	print('Copying files ...')
	for _, (copy_from, copy_to) in enumerate(mapped_files):
		filename = os.path.basename(copy_from)

		to_copy = os.path.join(copy_to, filename)
		print('- copying {} -> {}'.format(copy_from, to_copy))
		copyfile(copy_from, to_copy)


def main():
	generate_directories()
	copy_files()


if __name__ == '__main__':
	is_root = os.geteuid() == 0
	if is_root:
		sys.exit('Do NOT execute this script as root')
	main()
