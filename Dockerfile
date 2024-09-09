# syntax=docker/dockerfile:1
FROM debian:bookworm-slim AS qmk

WORKDIR /app

# https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/getting_started_build_tools.md
RUN apt update -y &&\
        apt install -y git

RUN git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git

FROM qmkfm/qmk_cli AS runner

WORKDIR /app

COPY --from=qmk /app/qmk_firmware ./qmk_firmware
RUN qmk setup -y -H ./qmk_firmware

COPY bin/build.sh ./

ENTRYPOINT ["./build.sh"]
