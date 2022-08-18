import os
import shutil
import unittest

from pathlib import Path
from logging import root


root_dir = '/var/system/openads'
config_dir = os.path.join(root_dir, 'config', 'camera', 'info')
storage_dir = os.path.join(root_dir, 'storage')


class TestDirectories(unittest.TestCase):
    def test_create_directory(self):

        config_src = os.path.abspath('./info.xml')

        rpath = Path(root_dir)
        rpath.parent.mkdir(parents=True, exist_ok=True)

        cpath = Path(config_dir)
        cpath.parent.mkdir(parents=True, exist_ok=True)

        spath = Path(storage_dir)
        spath.parent.mkdir(parents=True, exist_ok=True)

        shutil.copyfile(config_src, config_dir)
        check_info = Path(config_src)

    def test_config_dir(self):
        cpath = Path(config_dir)
        self.assertTrue(cpath.is_dir)

    def test_storage_dir(self):
        spath = Path(storage_dir)
        self.assertTrue(spath.is_dir)

    def test_info_xml(self):
        ipath = Path(os.path.join(config_dir, 'info.xml'))
        self.assertTrue(ipath.is_file)


if __name__ == '__main__':
    unittest.main()