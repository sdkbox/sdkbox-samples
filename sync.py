#!/usr/bin/python
# -*- coding: utf-8 -*-
#
# sync plugin sdk
#

import os
import errno
import sys
import subprocess
import json

from subprocess import call

def copy_dir(src, dst):
    call(["cp","-r",src,dst])

def rm_dir(src):
    call(["rm","-fr",src])

def merge(source, destination):
    """
    run me with nosetests --with-doctest file.py

    >>> a = { 'first' : { 'all_rows' : { 'pass' : 'dog', 'number' : '1' } } }
    >>> b = { 'first' : { 'all_rows' : { 'fail' : 'cat', 'number' : '5' } } }
    >>> merge(b, a) == { 'first' : { 'all_rows' : { 'pass' : 'dog', 'fail' : 'cat', 'number' : '5' } } }
    True
    """
    for key, value in source.items():
        if isinstance(value, dict):
            # get node or create one
            node = destination.setdefault(key, {})
            merge(value, node)
        else:
            destination[key] = value
    return destination

class Updater(object):
    def __init__(self, csc_dir, starer_kit_dir):

        self.csc_dir = csc_dir
        self.starer_kit_dir = starer_kit_dir
        self.build_v3_dir = os.path.join(self.csc_dir, "build/v3/plugins")
        self.sample_dir = os.path.join(self.csc_dir, "sample")
        self.sync_config = True

    def copy_plugin(self):
        root = self.build_v3_dir
        join = os.path.join
        for f in os.listdir(root):
            filepath = join(root, f)
            if os.path.isdir(filepath):
                print filepath
                copy_dir(join(filepath, "android/jni", "plugin"+f), join(self.starer_kit_dir, "frameworks/runtime-src/proj.android/jni/"))
                copy_dir(join(filepath, "android/libs/"), join(self.starer_kit_dir, "frameworks/runtime-src/proj.android/libs/"))
                for framework in os.listdir(join(filepath, "ios/")):
                    rm_dir(join(self.starer_kit_dir, "frameworks/runtime-src/proj.ios_mac/", framework))
                copy_dir(join(filepath, "ios/"), join(self.starer_kit_dir, "frameworks/runtime-src/proj.ios_mac/"))
                copy_dir(join(filepath, "js/"), join(self.starer_kit_dir, "frameworks/runtime-src/Classes/jsbindings/"))
                copy_dir(join(filepath, "lua/"), join(self.starer_kit_dir, "frameworks/runtime-src/Classes/luabindings/"))

    def sync_plugin_config(self):
        root = self.sample_dir
        join = os.path.join
        ret = {}
        for f in os.listdir(root):
            filepath = join(root, f)
            if not os.path.isdir(filepath):
                continue

            config_path = join(filepath, "Resources", "sdkbox_config.json")
            if not os.path.exists(config_path):
                config_path = join(filepath, "Resources", "res", "sdkbox_config.json")
                if not os.path.exists(config_path):
                    continue

            config = json.loads(open(config_path).read())
            ret = merge(ret, config)

        ret_str = json.dumps(ret, sort_keys=True, indent=4)
        open(join(self.starer_kit_dir, "res", "sdkbox_config.json"),'w').write(ret_str)

    def run(self):
        self.copy_plugin()
        self.sync_plugin_config()


if __name__ == '__main__':
    print len(sys.argv)
    if len(sys.argv) != 3:
        print "Usage: ", os.path.realpath(__file__) , "[csc_dir] [starer_kit_dir]"
        exit (1)

    Updater(sys.argv[1], sys.argv[2]).run()
