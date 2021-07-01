#!/bin/python3
# -*- coding: utf-8 -*-
# Конфигурация классов для генерации описания кластера kubernetes

class Item:
    types = {0: 'application', 1: 'pod', 2: 'service', 3: 'endpoint'}

    def __init__(self, type, name, **kwargs):
        self.type = type
        self.name = name
        self.var = kwargs

    def __str__(self):
        pass

    def to_html(self):
        pass


class Environment:
    def __init__(self, env):
        self.vars = {}
        for var in env:
            self.vars[var['name']] = var.get('value', None)


class ContainerCfg:
    def __init__(self, container):
        self.name = container['name']
        self.image = container['image'].split(':')[-1]
        if container.get('env', None):
            self.env = Environment(container['env'])

    def __str__(self):
        return self.image


class PodCfg:
    def __init__(self, pod):
        self.name = pod['metadata']['labels'].get('app', pod['metadata']['name'])
        self.labels = pod['metadata'].get('labels', self.name)
        self.containers = []
        for container in pod['spec']['containers']:
            self.containers.append(ContainerCfg(container))

    def __str__(self):
        return ','.join([str(container) for container in self.containers])


class ServiceCfg:
    types = ['loadBalancer', 'nodePort', 'clusterIP']

    def __init__(self, service):
        self.ports = []
        self.name = service['metadata']['name']
        self.selector = service['spec'].get('selector', None)
        for port in service['spec']['ports']:
            self.ports.append(port)

    def __str__(self):
        return ', '.join([f'{port.get("port")}:{port.get("nodePort", "None")}' for port in self.ports])


class IngressCfg:
    def __init__(self):
        pass


class NginxPublish:
    def __init__(self):
        pass


class Cluster:
    pods = {}
    services = {}
    ingress = {}
    nginx = {}

    def __init__(self, pods=None, services=None, ingress=None, nginx=None):
        self.applications = []
        if pods:
            self.get_pods(pods)
        if services:
            self.get_services(services)
        if ingress:
            self.get_ingress(ingress)
        if self.nginx:
            self.get_nginx(nginx)

    def get_pods(self, pods):
        for i in pods['items']:
            pod = PodCfg(i)
            Cluster.pods[pod.name] = pod

    def get_services(self, services):
        for i in services['items']:
            service = ServiceCfg(i)
            Cluster.services[service.name] = service

    def get_ingress(self, ingress):
        pass

    def get_nginx(self, nginx):
        pass


if __name__ == '__main__':
    print('Набор классов для реализации функциональности. Требуется запуск main.py')
