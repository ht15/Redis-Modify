FROM centos:7
COPY . /app
WORKDIR /app
RUN yum install -y vim
EXPOSE 5123
CMD make && ./sub_process
