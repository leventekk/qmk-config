DOCKER := "$(shell command -v docker)"
TIMESTAMP := "$(shell date -u +"%Y%m%d%H%M")"

DOCKER_TAG := qmk-builder
KEYMAP_PATH := /app/qmk_firmware/keyboards/crkbd/keymaps/crkbd_custom:ro

.PHONY: all clean

all:
	$(DOCKER) build --tag $(DOCKER_TAG) --file Dockerfile .
	$(DOCKER) run --rm -it --name $(DOCKER_TAG) \
		-v $(PWD)/config:$(KEYMAP_PATH) \
		-v $(PWD)/firmware:/app/firmware \
		-e TIMESTAMP=$(TIMESTAMP) \
		-e KEYMAP_NAME="crkbd_custom" \
		$(DOCKER_TAG)

clean:
	rm -f firmware/*
