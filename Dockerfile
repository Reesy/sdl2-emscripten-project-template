FROM node:stretch-slim

EXPOSE 3000

COPY ./embuild/resources ./embuild/resources

COPY ./embuild/index.html  \
     ./embuild/simple_sdl2_application.data \
     ./embuild/simple_sdl2_application.js \
     ./embuild/simple_sdl2_application.wasm \
     ./embuild

RUN npm install -g serve

CMD ["serve", "-s", "./embuild"]