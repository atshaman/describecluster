#!/bin/python3
# -*- coding: utf-8 -*-
""" Основной модуль программы для генерации описания кластера.
На входе - конфигурационный файл с указанием данных для парсинга, шаблонов и места вывода.
"""
import configparser
import os
import json
import classes

CFGFILE = r'/home/user/describecl/config.ini'
objects = {}

if __name__ == '__main__':
    config = configparser.ConfigParser()
    if os.path.exists(CFGFILE):
        config.read(CFGFILE)
    else:
        print('Конфигурация не обнаружена!')
        exit(-1)
    for i in config.options('input'):
        try:
            with open(config.get('input', i), 'r') as infile:
                objects[i] = json.load(infile)
        except OSError as err:
            print('Файл {0} не доступен для чтения'.format(config.get('input', i)))
        except json.JSONDecodeError as jserr:
            print('Файл {0} не является валидным json-файлом'.format(config.get('input', i)))
    cluster = classes.Cluster(**objects)
    for i, j in cluster.services.items():
        print(i, ':', j)
