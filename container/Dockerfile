FROM docker.io/debian:bookworm-slim

# Install basic tools
RUN apt-get update && apt-get install -y \
   curl \
   git \
   wget \
   vim \
   build-essential \
   cmake \
   m4 \
   gdb \
   gdbserver \
   && rm -rf /var/lib/apt/lists/*

# Accept build arguments
ARG USERNAME=developer
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user with specified UID/GID

# Clean out existing user/group with UID/GID if needed
RUN if getent passwd "${USER_UID}" > /dev/null; then \
      userdel -r "$(getent passwd "${USER_UID}" | cut -d: -f1)" || true; \
   fi && \
   if getent group "${USER_GID}" > /dev/null; then \
      groupdel "$(getent group "${USER_GID}" | cut -d: -f1)" || true; \
   fi

# Create group and user
RUN groupadd -g "${USER_GID}" "${USERNAME}" && \
   useradd -m -u "${USER_UID}" -g "${USER_GID}" -s /bin/bash "${USERNAME}"

# Make sure some working directory is owned by this user
RUN mkdir -p /app && chown -R ${USER_UID}:${USER_GID} /app

USER "${USERNAME}"
WORKDIR /app

# Keep container running
# CMD ["sleep", "infinity"]
# no need for CMD here, as the container will run indefinitely with the command in docker-compose.yml