#!/bin/env python

import os
import sys
import fcntl
import socket
import struct


def get_ip_address(ifname):
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	return socket.inet_ntoa(
		fcntl.ioctl(
			sock.fileno(),
			0x8195,
			struct.pack('256s', bytes(ifname[:15], 'utf-8'))
		)
		[20:24]
	)


def main():
	ip_addrs = get_ip_address('en0')


if __name__ == '__main__':
	main()
