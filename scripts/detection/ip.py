
import os
import sys
import argparse


def cli_args():
    parser = argparse.ArgumentParser(description='Scan/ Setup network devices.')
    parser.add_argument('scan', metavar='S', type=None, help='Scan for network device')
    return parser


def main():
    cargs = cli_args()
    args = cargs.parse_args()

if __name__ == '__main__':
    main()
