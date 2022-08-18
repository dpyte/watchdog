#!/bin/env python

import re
import subprocess as sp
import xml.etree.ElementTree as et


def query_devices():
	device_re = re.compile(b"Bus\s+(?P<bus>\d+)\s+Device\s+(?P<device>\d+).+ID\s(?P<id>\w+:\w+)\s(?P<tag>.+)$", re.I)
	df = sp.check_output('lsusb')
	devices = []
	for x in df.split(b'\n'):
		if x:
			info = device_re.match(x)
			if info:
				d_info = info.groupdict()
				d_info['device'] = '/dev/bus/usb/%s/%s' % (d_info.pop('bus'), d_info.pop('device'))
				devices.append(d_info)
	return devices


def main():
	devs = query_devices()
	xdoc = et.parse('/var/system/openads/config/camera/info/info.xml')



if __name__ == '__main__':
	main()

