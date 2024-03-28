#!/bin/bash

# Configure Network (Ethernet Wired) static PC for BBB and Host comminication

STATIC_IP="192.168.1.1"

echo "Setting Static IP $STATIC_IP for host PC"

nmcli con mod "Wired connection 1" ipv4.method manual ipv4.addresses "${STATIC_IP}/24" ipv4.gateway ""
nmcli con up "Wired connection 1"

echo "Setup Complete"