#!/bin/bash
filename="./address-book-database.csv"

# Controlla se il file esiste
if [[ ! -f $filename ]]; then
    echo "Errore: file $filename non trovato"
    exit 1
fi

# Controlla se l'argomento è stato fornito
if [[ -z $1 ]]; then
    echo "Errore: nessun argomento fornito"
    exit 1
fi

# Comandi principali
if [[ $1 == "view" ]]; then
    # Visualizza il contenuto del file in modo formattato e ordinato
    head -n 1 "$filename" | column -s "," -t
    tail -n +2 "$filename" | column -s "," -t | sort -k 4 -t ","
elif [[ $1 == "insert" ]]; then
    # Inserisce un nuovo record nel file
    caso1=$(head -1 "$filename" | cut -d "," -f 1)
    echo -n "${caso1}: "
    read var
    inserimento="$var"
    for (( i = 2; i <= 6; i++ )); do
        casoi=$(head -1 "$filename" | cut -f $i -d ",")
        echo -n "${casoi^}: "
        read var
        inserimento="$inserimento,$var"
        if (( $i == 4 )); then
            email=$(echo $inserimento | cut -f 4 -d ",")
            match=$(grep -w "$email" "$filename")
            if [[ ! -z $match ]]; then
                echo "Errore: Mail già presente"
                exit 1
            fi
        fi
        if (( $i == 6 )); then
            echo "$inserimento" >> "$filename"
            echo "Added"
        fi
    done
elif [[ $1 == "search" ]]; then
    # Cerca un record nel file
    if [[ -z $2 ]]; then
        echo "Errore: specificare il termine da cercare"
        exit 1
    fi
    IFS=$'\n'
    cerco=$2
    trovato=0
    for line in $(tail -n +2 "$filename"); do
        linea_verifica=$(echo "$line" | grep -w "$cerco")
        if [[ ! -z $linea_verifica ]]; then
            trovato=1
            IFS=","
            for (( i = 1; i <= 6; i++ )); do
                indice=$(head -1 "$filename" | cut -f $i -d ",")
                campo=$(echo "$linea_verifica" | cut -d "," -f $i)
                echo "${indice^}: $campo"
            done
            echo -e
        fi
    done
    if (( $trovato == 0 )); then
        echo "Not Found"
    fi
elif [[ $1 == "delete" ]]; then
    # Elimina un record dal file
    if [[ -z $2 ]]; then
        echo "Errore: specificare il termine da eliminare"
        exit 1
    fi
    elimina=$2
    verifica=$(grep -w -c "$elimina" "$filename")
    if (( verifica == 0 )); then
        echo "Cannot find any record"
        exit 1
    fi
    sed -i "/$elimina/d" "$filename"
    echo "Deleted"
else
    echo "Errore: argomento fornito non valido"
    exit 1
fi

# Ripristina l'IFS originale
IFS=$' \t\n'
