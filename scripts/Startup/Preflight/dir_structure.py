import pprint

from .util import Graph
from typing import Any, List, Type


def path_to_bin_dir() -> str:
	"""
	Returns path to where the project is located in the filesystem
	:return: string to path
	"""
	return '/var/system/openads'


class FileStructure:
	def __init__(self, tmp=None):
		"""
		Constructor method
		"""
		# Connections
		self.connections = [
			(path_to_bin_dir(), 'config'),
			(path_to_bin_dir(), 'execution'),
			(path_to_bin_dir(), 'storage'),

			# Config
			('config', 'camera'),
			('config', 'log'),
			('config', 'models'),
			('config', 'storage'),
			# Config -> Camera
			('camera', 'info'),
			('info', 'info.xml'),
			('info', 'registered_devices.xml'),
			# Config -> Log
			('log', 'log_config.yaml'),
			# Config -> models
			('models', 'elephant'),
			('elephant', 'elephant.config'),
			('elephant', 'scad_elephantnn_model.pt'),
			# Config -> Storage
			('storage', 'capacity'),
			# Config -> execution
			('execution', 'exec')
		]
		self.structure = Graph(self.connections, directed=True)

	def print_directory_structure(self):
		pprinter = pprint.PrettyPrinter()
		pprinter.pprint(self.structure.graph)
