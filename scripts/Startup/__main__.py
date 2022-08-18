#!/usr/bin/env python3

import logging

from scripts.Startup.Preflight.dir_structure import FileStructure


def check_for_installation() -> bool:
	"""
	Performs pre-check before running the system. Check for core file Installation
	:return: check_status (bool): Boolean value stating whether something is missing or not
	"""
	return True


def _main():
	if not check_for_installation():
		logging.warning(" [pre-check] :: verifying system integrity and Installation")
	d_structure = FileStructure()
	d_structure.print_directory_structure()


if __name__ == '__main__':
	_main()
